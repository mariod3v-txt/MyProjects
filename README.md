# 🛒 Store System with Authentication in C++

A terminal-based store management system developed in C++, featuring a basic authentication system (login/register) and role-based interaction between **customers and employees**.

This project was built as part of an academic assignment and to strengthen knowledge in **programming logic, file handling, and software testing concepts**.

---

## 🔐 Authentication System

* User registration
* Login validation
* Credentials stored in file (`users.txt`)

---

## 📌 Features

### 👤 Customer

* View available products
* Add items to cart
* View shopping cart
* Complete purchase
* Generate receipt in `.txt` file

### 👨‍💼 Employee

* Add new products to inventory
* View product list
* Update product prices
* Remove products

---

## 🛠️ Technologies Used

* C++
* Structured Programming
* File Handling (`fstream`)

---

## 📂 Project Structure

```
📁 project/
 ├── main.cpp
 ├── users.txt        # stored user credentials
 ├── products.txt     # product database
 └── receipts.txt     # generated purchase receipts
```

---

## 🧪 Test Cases

* ✔ Successful login
* ✔ Failed login (wrong password)
* ✔ User registration
* ✔ Duplicate user scenario
* ✔ Add/remove products
* ✔ Update product prices
* ✔ Purchase flow
* ✔ Empty cart handling

---

## ⚠️ Known Limitations

* Passwords are stored in plain text (not secure)
* No strong input validation
* Duplicate users may be allowed
* Uses Windows-only commands (`system("cls")`, `Sleep()`)

---

## 🔒 Security Note

This project uses a simple authentication system for learning purposes.
In real-world applications, passwords should be stored using secure hashing algorithms (e.g., SHA-256 or bcrypt).

---

## 🚀 Future Improvements

* Implement password hashing
* Add input validation and sanitization
* Prevent duplicate users
* Improve user interface
* Make the system cross-platform
* Add automated testing

---

## 🎯 Learning Goals

This project helped develop skills in:

* File manipulation
* Authentication logic
* Debugging and testing
* Understanding basic security flaws
* Structuring a complete software project

---

## 👨‍💻 Author

* Mário Avelino
