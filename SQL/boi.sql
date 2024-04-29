-- Inserting items into the database

-- Creating the 'products' table
CREATE TABLE products (
    id INTEGER PRIMARY KEY,
    Name TEXT,
    Brand TEXT,
    Category TEXT,
    Price REAL,
    Unit INTEGER,
    Sold INTEGER,
    Inventory INTEGER
);

-- Fruits
INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Valley', 'Fruits', 'Apple', 100, 1, 0, 50);

INSERT INTO products (Brand, Category, Name, Price, Unit,  Sold, Inventory)
VALUES ('Green Valley', 'Fruits', 'Bannana', 75, 12, 0, 50);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Valley', 'Fruits', 'Kinou Oranges', 125, 12, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Valley', 'Fruits', 'Honey Mango', 200, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Valley', 'Fruits', 'Strawberry', 700, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Valley', 'Fruits', 'Pear', 130, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Valley', 'Fruits', 'Pomogranite', 157, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Macintosh', 'Fruits', 'Granny Smith Apple', 200, 1, 0, 50);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Macintosh', 'Fruits', 'Fuji Apple', 1, 180, 0, 50);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Macintosh', 'Fruits', 'Golden Apple', 1, 300, 0, 50);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('United Fruit Company', 'Fruits', 'Bannana', 12, 125, 0, 50);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Juciy Citrus', 'Fruits', 'Fruiter Oranges', 144, 12, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Great Value', 'Fruits', 'Chaunsa Mango', 225, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Great Value', 'Fruits', 'Strawberry', 900, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Queen Fruits', 'Fruits', 'Pear', 135, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Queen Fruits', 'Fruits', 'Pomogranite', 110, 1, 0, 70);

-- Vegetables
INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Deco', 'Vegetables', 'Spinach', 100, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Deco', 'Vegetables', 'Cucumbers', 100, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Giant', 'Vegetables', 'Carrots', 100, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Giant', 'Vegetables', 'Bell Peppers', 75, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Giant', 'Vegetables', 'Onions', 80, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Giant', 'Vegetables', 'Potato', 60, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Valley', 'Vegetables', 'Garlic', 80, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Valley', 'Vegetables', 'Tomato', 180, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Deco', 'Vegetables', 'Eggplant', 140, 1, 0, 70);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Giant', 'Vegetables', 'Broccoli', 300, 1, 0, 70);

-- Herbs
INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Herb World', 'Herbs', 'Basil', 30, 0.25, 0, 210);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Herb World', 'Herbs', 'Mint', 20, 0.25, 0, 210);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Herb World', 'Herbs', 'Thyme', 100, 0.25, 0, 210);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Herb World', 'Herbs', 'Rosemary', 80, 0.25, 0, 120);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Herb World', 'Herbs', 'Sage', 60, 0.25, 0, 250);

-- Dairy

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Olpers', 'Dairy', 'Milk', 250, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Nurpur', 'Dairy', 'Milk', 240, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Adams', 'Dairy', 'Cheese', 500, 1, 0, 30);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Prima', 'Dairy', 'Cheese', 400, 1, 0, 30);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Young Fresh', 'Dairy', 'Yougurt', 290, 1, 0, 30);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Adams', 'Dairy', 'Yougurt', 320, 1, 0, 30);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Menu', 'Dairy', 'Eggs', 430, 12, 0, 60);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Omega', 'Dairy', 'Eggs', 430, 12, 0, 60);

-- Meat

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Fresh', 'Meat', 'Chicken Whole', 690, 1, 0, 20);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Fresh', 'Meat', 'Chicken Boneless', 990, 1, 0, 20);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Fresh', 'Meat', 'Beef Minced', 1100, 1, 0, 20);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Fresh', 'Meat', 'Beef Steak', 1300, 1, 0, 20);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Fresh', 'Meat', 'Fish Whole', 590, 1, 0, 20);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Fresh', 'Meat', 'Fish Fillet', 790, 1, 0, 20);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Fresh', 'Meat', 'Mutton Minced', 1090, 1, 0, 20);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Fresh', 'Meat', 'Mutton Steak', 1190, 1, 0, 20);

-- Bakery

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Bread and Beyond', 'Bakery', 'Bread', 270, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Dawn', 'Bakery', 'Bread', 250, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Homemade', 'Bakery', 'Pastries', 270, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('KnNs', 'Bakery', 'Pastries',  370, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Fresh', 'Bakery', 'Cake',  1170, 1, 0, 40);

-- Frozen

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('KnNs', 'Frozen', 'Shami Kebab',  1300, 12, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Menu', 'Frozen', 'Shami Kebab',  1350, 12, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('KnNs', 'Frozen', 'Chicken Tenders', 800, 20, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Menu', 'Frozen', 'Chicken Tenders', 900, 20, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Walls', 'Frozen', 'Strawberry Ice Cream', 1100, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Omore', 'Frozen', 'Strawberry Ice Cream', 1000, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Walls', 'Frozen', 'Chocolate Ice Cream', 1100, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Omore', 'Frozen', 'Chocolate Ice Cream', 1000, 1, 0, 40);

-- Canned

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Del Monte', 'Canned', 'Corn', 400, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Green Giant', 'Canned', 'Pineapple', 500, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Americana', 'Canned', 'Tomato Paste', 450, 1, 0, 40);

-- Pantry

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Gold', 'Pantry', 'Basmati Rice', 400, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Bake Parlor', 'Pantry', 'Macaroni Pasta', 250, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Bake Parlor', 'Pantry', 'Elbow Pasta', 250, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Fauji', 'Pantry', 'Oatmeal', 300, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('Punjab Gold', 'Pantry', 'Flour', 400, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('National', 'Pantry', 'Sugar', 400, 1, 0, 40);

INSERT INTO products (Brand, Category, Name, Price, Unit, Sold, Inventory)
VALUES ('National', 'Pantry', 'Salt', 400, 1, 0, 40);

--Snacks

INSERT INTO products (
                         Inventory,
                         Sold,
                         Unit,
                         Price,
                         Category,
                         Brand,
                         Name,
                         id
                     )
                     VALUES (
                         50,
                         0,
                         1,
                         60,
                         'Snacks',
                         'PepsiCo',
                         'Kurkure',
                         71
                     ),
                     (
                         50,
                         0,
                         1,
                         80,
                         'Snacks',
                         'Simba Foods',
                         'Macho Nachos',
                         72
                     ),
                     (
                         20,
                         0,
                         1,
                         800,
                         'Snacks',
                         'PepsiCo',
                         'Pringles',
                         73
                     ),
                     (
                         50,
                         0,
                         1,
                         60,
                         'Snacks',
                         'Pepsico',
                         'Lays Masala',
                         74
                     ),
                     (
                         25,
                         0,
                         1,
                         480,
                         'Snacks',
                         'PepsiCo',
                         'Doritos',
                         75
                     ),
                     (
                         50,
                         0,
                         1,
                         100,
                         'Snacks',
                         'PepsiCo',
                         'Cheetos',
                         76
                     ),
                     (
                         50,
                         0,
                         1,
                         180,
                         'Snacks',
                         'Nutribel',
                         'Noms Nachos',
                         77
                     ),
                     (
                         50,
                         0,
                         1,
                         40,
                         'Snacks',
                         'Kraft Food',
                         'Oreos',
                         78
                     ),
                     (
                         50,
                         0,
                         1,
                         40,
                         'Snacks',
                         'EBM',
                         'Peanut Pik',
                         79
                     ),
                     (
                         50,
                         0,
                         1,
                         40,
                         'Snacks',
                         'Lu',
                         'Gluco',
                         80
                     ),
                     (
                         50,
                         0,
                         1,
                         40,
                         'Snacks',
                         'Lu',
                         'Chocolato',
                         81
                     ),
                     (
                         50,
                         0,
                         1,
                         50,
                         'Snacks',
                         'Super Crisps',
                         'Catty Chins',
                         82
                     ),
                     (
                         50,
                         0,
                         1,
                         25,
                         'Snacks',
                         'Peak Freans',
                         'Cocomo',
                         83
                     ),
                     (
                         50,
                         0,
                         1,
                         40,
                         'Snacks',
                         'Lu',
                         'Super',
                         84
                     ),
                     (
                         50,
                         0,
                         1,
                         40,
                         'Snacks',
                         'Peak Freans',
                         'Marie',
                         85
                     );
