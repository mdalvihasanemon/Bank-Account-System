
---

# Bank Account System

A basic implementation of a banking system using C++. The system allows users to create new accounts, deposit and withdraw money, check balances, and transfer funds between accounts.

## Features
- **Account Creation**: Users can create new accounts by providing personal details and an initial deposit amount.
- **Deposit**: Users can deposit funds into their accounts.
- **Withdrawal**: Users can withdraw funds from their accounts with checks for sufficient balance.
- **Balance Inquiry**: Users can check their account balance at any time.
- **Fund Transfer**: Users can transfer funds between accounts.
- **Account Management**: Ability to view account details and transaction history.

## How the Code Works

### Header Inclusions
The program includes essential header files like:
- `<iostream>`: For input-output operations.
- `<string>`: For string manipulation, used in account details like account number and password.

### Namespace Declaration
The program utilizes the `std` namespace, allowing access to standard library functions like `std::cout`, `std::cin`, etc.

### BankAccount Class

#### Private Members:
- **MAX_ACCOUNTS**: A constant defining the maximum number of accounts allowed in the system.
- **Account**: A structure defining the account details like:
  - `accountNumber`: Unique account number.
  - `password`: Account password.
  - `name`: Name of the account holder.
  - `balance`: Current balance of the account.
- **accounts**: An array of `Account` structures that holds the account details for multiple users.
- **accountCount**: An integer to keep track of how many accounts are created.
- **changeACnumber**: An integer used to generate unique account numbers for each new account.

#### Public Members:
- **Constructor `BankAccount()`**: Initializes the system with predefined account data and sets up the account details by calling `initializeAccounts()`.
- **`initializeAccounts()`**: Populates the accounts with some initial data.
- **`getData()`**: The entry point for user interaction. It asks if the user has an existing account or wants to create a new one.
- **`getExistingAccountData()`**: Prompts the user to enter their existing account number and password for authentication.
- **`createNewAccount()`**: Allows the user to create a new account by providing necessary details like name, initial deposit, and password.
- **`generateAccountNumber()`**: Generates a unique account number for each new account.
- **`handleTransaction()`**: Manages different types of transactions like withdrawal, deposit, transfer, and exit.
- **`deposit()`**: Allows the user to deposit money into an account.
- **`matchData()`**: Verifies if the entered account number and password match an existing account.
- **`withdraw()`**: Allows users to withdraw money from their account.
- **`transfer()`**: Handles transferring funds from one account to another.
- **`exit()`**: Exits the program.

### Main Function:
- The main function creates an object of the `BankAccount` class and invokes `getData()` to initiate the banking system.

### Flow of Execution:
1. The program begins by asking the user whether they have an existing account or need to create one.
2. If the user has an existing account, they are prompted to enter their account number and password for authentication.
3. If the user does not have an account, they are prompted to create one by providing their name, password, and an initial deposit.
4. Once authenticated or after creating a new account, the user can perform transactions such as:
   - Depositing funds
   - Withdrawing funds
   - Transferring funds
   - Exiting the system
5. After each transaction, the system returns to the main menu until the user chooses to exit.

### Recursive Calls:
- Some functions, such as `getData()` and `deposit()`, use recursive calls to allow re-execution when invalid input is provided. For example, if the user enters incorrect details, the program will prompt them again until valid input is provided.

### Limitations:
- **No Persistent Storage**: The system does not use file or database storage. Therefore, all data (such as accounts and transactions) is lost when the program ends.
- **Minimal Error Handling**: There is limited error handling for invalid inputs or operations.
- **Security**: Passwords are stored in plaintext, which is not secure for real-world applications. In a real-world system, passwords should be hashed and stored securely.

## Compilation and Running

### Steps to Compile and Run:

1. **Clone the Repository**:
   ```
   git clone https://github.com/mdalvihasanemon/bank-account-system.git
   cd bank-account-system
   ```

2. **Compile the Code**:
   ```
   g++ -o bank_account_system main.cpp
   ```

3. **Run the System**:
   ```
   ./bank_account_system
   ```

### Example:

1. **Create a new account**:
   ```
   Enter name: John Doe
   Enter initial deposit: 1000
   Account created successfully!
   ```

2. **Deposit funds**:
   ```
   Enter deposit amount: 500
   Deposit successful! New balance: 1500
   ```

3. **Withdraw funds**:
   ```
   Enter withdrawal amount: 200
   Withdrawal successful! New balance: 1300
   ```

## System Design

### Classes and Functions:
- **Account Class**: Manages individual customer accounts, including account creation, balance tracking, and transaction methods.
- **Bank Class**: Manages a collection of accounts, performs fund transfers, and tracks global transactions.
- **Transaction History**: Tracks deposits, withdrawals, and transfers for each account.

### Main Components:
- **main.cpp**: Entry point for the system. Interacts with the user and manages the flow of operations.
- **account.cpp**: Handles account-related operations.
- **bank.cpp**: Contains functions to manage multiple accounts.

## Contributing

1. Fork the repository
2. Create a new branch (`git checkout -b feature-name`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature-name`)
5. Open a pull request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

This expanded explanation covers the program flow, class structure, and functionality in more detail.
