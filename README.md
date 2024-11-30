# Run C++ in VSCode

This guide will walk you through the steps to compile and run a C++ program in Visual Studio Code (VSCode) using the `clang++` compiler.

## Prerequisites

Before you begin, ensure that you have the following:

- **Visual Studio Code** installed. You can download it from [here](https://code.visualstudio.com/).
- **clang++** installed on your system.
  - **macOS**: `clang++` is pre-installed with Xcode Command Line Tools. Install it with:
    ```bash
    xcode-select --install
    ```
  - **Linux**: Install `clang++` using the package manager:
    ```bash
    sudo apt install clang
    ```
  - **Windows**: Please follow these instruction from [Using GCC with MinGW](https://code.visualstudio.com/docs/cpp/config-mingw).

---

## Steps to Compile and Run C++ Code

### 1. Open the Integrated Terminal

- In VSCode, open the **Integrated Terminal** by navigating to:
  - **View > Terminal**
  - Or press `Ctrl + J` (or `Cmd + J` on macOS) to open the terminal.

### 2. Compile the C++ Program with `clang++`

- In the terminal, run the following command to compile your `main.cpp` file using `clang++`:

  ```bash
  clang++ -o main main.cpp
  ```

- This will generate an executable file named main.

### 3. Run the Executable

- After building the program, you can run it directly from the terminal by typing:

  ```bash
  ./main
  ```

- You should see the following output:

  ```bash
  Hello, World!
  ```
