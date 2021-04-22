CREATE USER 'byeori'@'localhost' IDENTIFIED BY 'byeori';
GRANT ALL PRIVILEGES ON *.* TO 'byeori'@'localhost' WITH GRANT OPTION;
FLUSH PRIVILEGES;
CREATE DATABASE wordpress;
USE wordpress;
