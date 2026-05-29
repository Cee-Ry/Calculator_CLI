# calc — Calculator CLI

A lightweight command-line calculator built in C++. Instead of opening an app or typing into a prompt, you run calculations directly from your terminal as a command — just like `ls`, `grep`, or `echo`.

```bash
calc 10 + 5 20
# Result: 35
```

---

## Features

- Runs as a native terminal command (`calc`)
- Supports addition, subtraction, multiplication, and division
- Accepts **multiple numbers** in a single operation
- Operator can be written as a symbol (`+`, `-`, `x`, `/`) or as a word (`add`, `subtract`, `multiply`, `divide`)
- Installs to `~/.local/bin` for system-wide access

---

## Requirements

- A C++ compiler (GCC or Clang)
- CMake 3.10 or higher
- Linux or macOS (or Windows with WSL)

---

## Build & Install

```bash
# 1. Clone the repository
git clone https://github.com/yourusername/Calculator_CLI.git
cd Calculator_CLI

# 2. Create a build directory and compile
cmake -B build
cmake --build build

# 3. Install the `calc` command to ~/.local/bin
cmake --install build
```

> Make sure `~/.local/bin` is in your `PATH`. If it's not, add this line to your `~/.bashrc` or `~/.zshrc`:
> ```bash
> export PATH="$HOME/.local/bin:$PATH"
> ```
> Then reload your shell: `source ~/.bashrc`

---

## Usage

```
calc <number> [numbers...] <operator> [more numbers...]
```

The operator and numbers can be passed in **any order** — the program collects all integers and picks up the operator regardless of position.

### Operators

| Symbol | Word       | Operation      |
|--------|------------|----------------|
| `+`    | `add`      | Addition        |
| `-`    | `subtract` | Subtraction     |
| `x`    | `multiply` | Multiplication  |
| `/`    | `divide`   | Division        |

### Examples

```bash
# Addition
calc 1 2 3 +
# Result: 6

# Subtraction
calc 100 - 25 10
# Result: 65

# Multiplication
calc 4 x 5
# Result: 20

# Division (integer division)
calc 100 / 4
# Result: 25

# Using word operators
calc 6 7 8 add
# Result: 21
```

> **Note:** Division uses integer arithmetic — remainders are truncated (e.g., `7 / 2` → `3`).

---

## How It Works

`calc` is a standard C++ program that reads command-line arguments (`argc`/`argv`). It scans through the arguments, separates numbers from operators, and then calls the matching function (`sum`, `difference`, `product`, or `quotient`) on the collected numbers.

The CMake `install` target places the compiled binary at `~/.local/bin/calc`, making it accessible from anywhere in your terminal.

---

## Project Structure

```
Calculator_CLI/
├── main.cpp          # All source code
├── CMakeLists.txt    # Build and install configuration
└── .gitignore        # Excludes build artifacts and binaries
```

---

## License

This project is open source. Feel free to use, modify, and share.
