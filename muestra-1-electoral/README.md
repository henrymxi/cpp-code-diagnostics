# Diagnostic Report 01: Electoral System (C++)

## 1. Issue Summary
* **Language:** C++11 / C++14
* **Domain:** Structural Logic, Memory Management & Flow Control
* **Primary Bugs Identified:**
  1. Vector state mismatch (`ListaVotante` was not cleared when resetting votes).
  2. Typos in function signatures (`CalcualrPorcentajeVotos`).
  3. OS-dependent terminal clear command (`system("clear")` failing on Windows).
  4. Abrupt exit flow (`exit(0)`) causing unhandled loop breaks.

## 2. Root Cause Analysis & Fix
- **State Inconsistency:** Added `ListaVotante.clear();` inside Case 6 to prevent demographic stats from persisting after resetting urns.
- **Portability:** Replaced OS-hardcoded clears with conditional `#ifdef _WIN32` preprocessor directives.
- **Control Flow:** Replaced `exit(0)` inside switch loops with controlled `return 0;` breaks.

## 3. Execution Proof
- Compiled successfully with `g++ -std=c++11 -Wall`
- Verified correct demographic calculations after urn reset.
