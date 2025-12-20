#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
YELLOW='\033[1;33m'
RESET='\033[0m'

# Path to your executable
PHILO="./philo"

# Check if executable exists
if [ ! -f "$PHILO" ]; then
    echo -e "${RED}Error: $PHILO executable not found. Please run 'make' first.${RESET}"
    exit 1
fi

echo -e "${CYAN}==============================================${RESET}"
echo -e "${CYAN}    PHILOSOPHERS ARGUMENT PARSING TESTS      ${RESET}"
echo -e "${CYAN}==============================================${RESET}\n"

# Function to run a single test case
# Usage: run_test "Test Name" "EXPECTED_RESULT" "ARGS"
run_test() {
    TEST_NAME="$1"
    EXPECTED="$2"
    ARGS="$3"

    # Run the program with a 0.5s timeout.
    # We redirect stdout and stderr to /dev/null to keep the terminal clean.
    timeout 0.5s $PHILO $ARGS > /dev/null 2>&1
    RET=$?

    # Logic to determine Pass/Fail
    if [ "$EXPECTED" == "FAIL" ]; then
        # Case: We expect the program to error out
        if [ $RET -eq 139 ]; then
            echo -e "${RED}[FAIL] ${TEST_NAME} (SEGFAULT Detected!)${RESET}"
        elif [ $RET -ne 0 ] && [ $RET -ne 124 ]; then
            # 124 is the timeout exit code (meaning it kept running).
            # Any other non-zero code usually means the program handled the error and exited.
            echo -e "${GREEN}[PASS] ${TEST_NAME}${RESET}"
        elif [ $RET -eq 124 ]; then
             echo -e "${RED}[FAIL] ${TEST_NAME} (Simulation started but should have failed)${RESET}"
        else
            echo -e "${RED}[FAIL] ${TEST_NAME} (Program exited with 0, but should have failed)${RESET}"
        fi

    elif [ "$EXPECTED" == "PASS" ]; then
        # Case: We expect the program to run successfully
        if [ $RET -eq 124 ]; then
            # Timeout means it was running successfully for 0.5s
            echo -e "${GREEN}[PASS] ${TEST_NAME}${RESET}"
        elif [ $RET -eq 0 ]; then
            # Exit 0 is also acceptable (e.g., eating 0 times finishes instantly)
            echo -e "${GREEN}[PASS] ${TEST_NAME}${RESET}"
        elif [ $RET -eq 139 ]; then
             echo -e "${RED}[FAIL] ${TEST_NAME} (SEGFAULT Detected!)${RESET}"
        else
            echo -e "${RED}[FAIL] ${TEST_NAME} (Program returned error code $RET)${RESET}"
        fi
    fi
}

# --- 1. Argument Count Errors ---
echo -e "${YELLOW}--- Category 1: Argument Count ---${RESET}"
run_test "No Arguments"          "FAIL" ""
run_test "Missing Argument"      "FAIL" "4 310 200"
run_test "Too Many Arguments"    "FAIL" "4 310 200 100 5 1"

# --- 2. Syntax & Format Errors ---
echo -e "\n${YELLOW}--- Category 2: Syntax & Format ---${RESET}"
run_test "Text Input"            "FAIL" "four 310 200 100"
run_test "Mixed Alphanumeric"    "FAIL" "4 310ms 200 100"
run_test "Floating Point"        "FAIL" "4 310.5 200 100"
run_test "Empty String"          "FAIL" "'' 310 200 100"
run_test "Whitespace String"     "FAIL" "'   ' 310 200 100"
run_test "Just a Sign (+)"       "FAIL" "+ 310 200 100"
run_test "Double Sign (++)"      "FAIL" "++4 310 200 100"

# --- 3. Logic Constraints ---
echo -e "\n${YELLOW}--- Category 3: Logic Constraints ---${RESET}"
run_test "Negative Philosophers" "FAIL" "-4 310 200 100"
run_test "Negative Time"         "FAIL" "4 -310 200 100"
run_test "Zero Philosophers"     "FAIL" "0 310 200 100"
run_test "Negative Meal Count"   "FAIL" "4 310 200 100 -5"

# --- 4. Integer Overflow ---
echo -e "\n${YELLOW}--- Category 4: Integer Limits ---${RESET}"
run_test "INT_MAX + 1"           "FAIL" "2147483648 310 200 100"
run_test "Long Overflow"         "FAIL" "99999999999999999 310 200 100"
run_test "INT_MIN"               "FAIL" "-2147483648 310 200 100"

# --- 5. Valid Tricky Inputs ---
echo -e "\n${YELLOW}--- Category 5: Valid Inputs (Should Run) ---${RESET}"
run_test "Explicit Plus Sign"    "PASS" "+4 +310 +200 +100"
run_test "Leading Zeros"         "PASS" "004 00310 0200 0100"
run_test "Zero Meal Count"       "PASS" "4 310 200 100 0"

echo -e "\n${CYAN}Done.${RESET}"
