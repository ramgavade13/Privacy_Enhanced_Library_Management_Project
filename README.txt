
Privacy-Enhanced Library Management System with Encrypted Login
------------------------------------------------------------------
What is included:
- main.cpp           : Full C++ source code (single-file)
- users.txt          : (auto-created) stores registered users as username|passwordHash
- books.txt          : (auto-created) stores books as id|title|author|isIssued
- Project_Report.pdf : Project report with problem statement, flow, methodology, and instructions
- README.txt         : This file with instructions to compile/run

Notes:
- The project uses a portable salted std::hash for password hashing (educational purpose).
- On first run, sample books are added automatically if books.txt is missing.
- users.txt and books.txt are created/updated in the same folder, so keep them together with the executable.
- For stronger hashing (SHA-256), replace the hash function with an implementation using OpenSSL or a library.
- If you want the code split into multiple files (user.h/cpp, library.h/cpp), ask and I will provide it.
------------------------------------------------------------------
