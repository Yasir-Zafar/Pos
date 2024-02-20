-- Inserting items into the database

-- Creating the 'products' table
CREATE TABLE products (
    id INTEGER PRIMARY KEY,
    Brand TEXT,
    Category TEXT,
    Name TEXT,
    Price REAL,
    Units INTEGER,
    Sold INTEGER,
    Inventory INTEGER
);

-- Fruits
INSERT INTO products (brand, Category, name, price, units, sold, inventory)
VALUES ('Green Valley', 'Fruits', 'Apple', 1.99, 10, 0, 50);
