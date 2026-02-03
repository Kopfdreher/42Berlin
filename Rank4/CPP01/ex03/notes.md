# Pointer vs Reference Logic (The "Why")
*   **`HumanA` (Reference):** Since `HumanA` is *always* armed and receives the weapon in the constructor, a **reference** is best. References cannot be null and must be initialized, enforcing the rule that `HumanA` always has a weapon.
*   **`HumanB` (Pointer):** Since `HumanB` starts without a weapon and sets it later, a **pointer** is best. Pointers can be `NULL` (indicating no weapon) and can be reassigned later via `setWeapon`.
