# Objects_Classes_Lab

A C++ class for simulating basic banking operations for multiple accounts.

## Data Dictionary

| Attribute                 | Data Type     | Description                            |
|---------------------------|---------------|----------------------------------------|
| `accountNumber`           | `std::string` | The account's number.                  |
| `account HolderName`      | `std::string` | The book's author.                     |
| `name`                    | `std::string` | The name of the account.               |
| `balance`    `            | `double`      | The # of money in the account.         |
| `number`                  | `std::string` | Used when changing account's number    |
| `name`                    | `std::string` | Used when changing account's name      |
| `amount`                  | `std::string` | Used when changing account's balance   |

## Methods List

| Method Signature             | Return Type   | Description               |
|------------------------------|---------------|---------------------------|
| `BankBalance()`                      | (Constructor) | Default constructor.                |
| `BankBalance(number, name, amount)`  | (Constructor) | Parameterized constructor.          |
| `getAccountNumber() const`           | `std::string` | Gets the account's number.          |
| `getAccountHolderName() const`       | `std::string` | Gets the account's holder's name.   |
| `getBalance()`                       | `double`      | returns balance.                    |
| `setAccountHolderName()`             | `void`        | Changes account's holder's name.    |
| `SetAccountNumber()`                 | `void`        | Changes account's number            |
| `deposit()`                          | `void`        | Adds to balance                     |
| 'withdraw()`                         | `void`        | Subtracts from balance              |
