# Employee Data Management System

This is a simple Employee Data Management System implemented in C. The system allows you to perform various operations related to employee records, such as creating, adding, deleting, searching, modifying, and listing records based on different criteria.

## Table of Contents

- [Features](#features)
- [How to Use](#how-to-use)
- [Options](#options)
- [File Structure](#file-structure)
- [Compilation](#compilation)
- [Contributing](#contributing)
- [License](#license)

## Features

- Create a new record or add a new record to the existing data.
- Delete a record based on the Employee ID.
- Search for a record based on the Employee ID.
- Modify a record based on the Employee ID.
- List records based on various criteria:
  - List all professors.
  - List employees older than 55.
  - List all male employees.
  - List all female employees.
  - List all employees of a specific department.
  - List employees with a specific designation.
  - List all records.

## How to Use

1. Clone the repository:

    ```bash
    git clone https://github.com/omerkhathab/Employee-Management-System-C.git
    ```

2. Navigate to the project directory:

    ```bash
    cd Employee-Management-System-C
    ```

3. Compile the code:

    ```bash
    gcc project.c -o employee_management_system
    ```

4. Run the executable:

    ```bash
    ./employee_management_system
    ```

## Options

- **Create a New Record or Add a New Record**
- **Delete a Record**: Delete a record based on the Employee ID.
- **Search for a Record**: Search for a record based on the Employee ID.
- **Modify a Record**: Modify a record based on the Employee ID.
- **List Records**: List records based on various criteria:
  - List all professors.
  - List employees older than 55.
  - List all male employees.
  - List all female employees.
  - List all employees of a specific department.
  - List employees with a specific designation.
  - List all records.

## File Structure

- **EmpData.txt**: Data file storing employee records.
- **employee_management_system.c**: C source code file.

## Compilation

To compile the code, use the following command:

```bash
gcc employee_management_system.c -o employee_management_system
```

## Contributing

Feel free to contribute to this project by opening issues or submitting pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.