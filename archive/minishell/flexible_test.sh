#!/bin/bash

# ==============================================================================
# FLEXIBLE MINISHELL TESTER
# Usage: ./flexible_test.sh [path_to_shell]
# Examples:
#   ./flexible_test.sh             -> Tests ./minishell (Default)
#   ./flexible_test.sh bash        -> Tests bash vs bash (Sanity Check)
#   ./flexible_test.sh zsh         -> Tests zsh vs bash
# ==============================================================================

# 1. DETERMINE WHICH SHELL TO TEST
if [ -n "$1" ]; then
    MSH="$1"
else
    MSH="./minishell"
fi

# Colors
RESET="\033[0m"
GREEN="\033[32m"
RED="\033[31m"
CYAN="\033[36m"
YELLOW="\033[33m"

echo -e "${CYAN}--- Testing Target: ${YELLOW}$MSH${CYAN} ---${RESET}"

# 2. CHECK IF SHELL EXISTS (File path OR System command)
if [ ! -f "$MSH" ] && ! command -v "$MSH" &> /dev/null; then
    echo -e "${RED}Error: Executable '$MSH' not found.${RESET}"
    echo "Usage: ./flexible_test.sh [path_to_shell]"
    exit 1
fi

# Function to run a test
run_test() {
    CMD="$1"
    DESC="$2"

    # --- A. Run in REFERENCE SHELL (BASH) ---
    # We use bash as the "Gold Standard" to compare against
    EXPECTED=$(echo "$CMD" | bash 2>&1)
    EXIT_BASH=$?

    # --- B. Run in TARGET SHELL (Your Minishell, Bash, Zsh, etc) ---
    ACTUAL=$(echo "$CMD" | "$MSH" 2>&1)
    EXIT_MSH=$?

    # --- C. Output Cleanup ---
    # 1. Remove "minishell$ " prompt (Standard 42 prompt)
    # 2. Remove "exit" message (Readline sometimes prints this on EOF)
    # 3. Remove bash prompt if testing bash interactive (unlikely in pipe, but safe to add)
    ACTUAL=$(echo "$ACTUAL" | sed 's/^minishell\$ //g' | sed 's/^minishell$//g')
    ACTUAL=$(echo "$ACTUAL" | sed '/^exit$/d')

    # --- D. Compare ---
    if [ "$ACTUAL" == "$EXPECTED" ] && [ "$EXIT_MSH" == "$EXIT_BASH" ]; then
        printf "${GREEN}[OK]${RESET} %-50s \n" "$DESC"
    else
        printf "${RED}[KO]${RESET} %-50s \n" "$DESC"
        echo "   >> CMD:      $CMD"
        echo "   >> Expected: [$EXPECTED] (Exit: $EXIT_BASH)"
        echo "   >> Got:      [$ACTUAL] (Exit: $EXIT_MSH)"
    fi
}

# ==========================================
# TEST SUITE
# ==========================================

echo -e "\n${YELLOW}>>> Binaries & Commands${RESET}"
run_test "/bin/ls"              "Absolute path binary"
run_test "ls"                   "PATH resolution"
run_test "ls -la"               "Arguments"
run_test "/bin/echo hello"      "Absolute path echo"
run_test "     ls      "        "Weird spacing"

echo -e "\n${YELLOW}>>> Echo Builtin${RESET}"
run_test "echo hello world"     "Basic Echo"
run_test "echo -n hello"        "Echo -n"
run_test "echo"                 "Echo empty"

echo -e "\n${YELLOW}>>> Quotes & Variables${RESET}"
run_test "echo '$USER'"         "Single quotes (No expansion)"
run_test "echo \"$USER\""       "Double quotes (Expansion)"
run_test "echo '\"'"            "Mixed quotes 1"
run_test "echo \"'\""           "Mixed quotes 2"

echo -e "\n${YELLOW}>>> Builtins${RESET}"
run_test "pwd"                                  "PWD"
run_test "cd /; pwd"                            "CD Absolute"
run_test "cd /tmp; pwd"                         "CD Relative"
run_test "export VAR=123; echo \$VAR"           "Export"
run_test "export VAR=123; unset VAR; echo \$VAR" "Unset"
run_test "exit 42"                              "Exit Code"

echo -e "\n${YELLOW}>>> Pipes & Redirections${RESET}"
echo "content" > infile.txt
run_test "ls | wc -l"                           "Simple Pipe"
run_test "cat < infile.txt"                     "Input Redirection <"
run_test "echo test > outfile.txt; cat outfile.txt" "Output Redirection >"

# Cleanup
rm -f infile.txt outfile.txt

echo -e "\n${CYAN}--- Tests Completed ---${RESET}"
