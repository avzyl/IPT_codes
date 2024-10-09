# IPT_codes Guide
Arduino ESP8266 Setup and Database Integration Guide

---

Step 1: Set Up XAMPP
1. Download XAMPP from https://www.apachefriends.org/index.html.
2. Install XAMPP on your computer and start the Apache and MySQL modules from the XAMPP control panel.

---

Step 2: Download Arduino IDE
1. Go to the official Arduino website: https://www.arduino.cc/en/software.
2. Download and install the Arduino IDE (version 1.8 or later is recommended).

---

Step 3: Configure Arduino IDE for ESP8266
1. Open Arduino IDE.
2. Navigate to File > Preferences.
3. In the "Additional Board Manager URLs" field, paste the following URL:
   http://arduino.esp8266.com/stable/package_esp8266com_index.json
4. Click OK.

---

Step 4: Install ESP8266 Board
1. In the Arduino IDE, go to Tools > Board > Boards Manager.
2. Search for ESP8266.
3. Click Install on the "ESP8266 by ESP8266 Community" package.
4. Wait for the installation to complete.

---

Step 5: Install MySQL Connector for Arduino
1. In the Arduino IDE, go to Sketch > Include Library > Manage Libraries.
2. In the Library Manager, search for MySQL Connector Arduino by Dr. Charles Bell.
3. Click Install.
   - If you encounter errors with this library, replace the file MySQL_Encrypt_Sha1.cpp with the modified version that contains proper return statements for the Encrypt_SHA1::write functions.

---

Step 6: Open and Modify the .ino File
1. Open the With_database.ino file (or your Arduino code file that interacts with the database).
2. Make the necessary changes according to your project requirements, such as updating the database credentials, Wi-Fi credentials, etc.

---

Step 7: Verify the Arduino Code
1. Click the Verify button (the checkmark) in the Arduino IDE to compile the code and ensure there are no errors.

---

Database and User Account Setup

---

Step 1: Create a Database in MySQL
1. Open phpMyAdmin from the XAMPP control panel (usually at http://localhost/phpmyadmin).
2. Click on the Databases tab.
3. Under "Create database," type your desired database name (e.g., arduino_data).
4. Click Create.

---

Step 2: Create a MySQL User Account
1. In phpMyAdmin, click on the User Accounts tab.
2. Scroll down and click Add user account.
3. Fill in the following fields:
   - Username: Enter your preferred username.
   - Host: Select Local from the dropdown (localhost).
   - Password: Enter a secure password.
4. Under Global privileges, select Check all to give the user full access to the database.
5. Click Go to create the account.

---

Step 3: Grant Privileges to the User
1. In phpMyAdmin, go to the User Accounts tab.
2. Find your created user and click Edit privileges.
3. Under "Database-specific privileges," select your newly created database (arduino_data).
4. Check all privileges for this user on this database.
5. Click Go to save.

---

Additional Information:
- Ensure your ESP8266 is properly connected to your Wi-Fi.
- Make sure the MySQL server is running in XAMPP when testing the Arduino-MySQL connection.

---

End of Guide

