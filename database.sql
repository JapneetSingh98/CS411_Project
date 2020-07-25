CREATE TABLE Users(
UserID varchar(50) NOT NULL,
UserName varchar(255),
PRIMARY KEY (UserID)
);

CREATE TABLE Pantry(
Name varchar(255) NOT NULL,
Quantity INT,
ExpirationDate DATE,
PRIMARY KEY(Name)
);

CREATE TABLE Recipe(
ID INT NOT NULL,
Name varchar(255),
Instructions varchar (1000),
PrepTime INT,
CookTime INT,
Servings INT,
PRIMARY KEY(ID)
);

CREATE TABLE Ingredients(
ID INT NOT NULL,
Name varchar(255) NOT NULL,
Quantity FLOAT,
Type varchar(50),
PRIMARY KEY(Name, RecipeName),
FOREIGN KEY(ID) REFERENCES Recipe(ID) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE MealType(
ID INT NOT NULL,
Type varchar(255) NOT NULL,
PRIMARY KEY(ID, Type),
FOREIGN KEY(ID) REFERENCES Recipe(ID) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE DietaryRestrictions(
ID INT NOT NULL,
Restriction varchar(255) NOT NULL,
PRIMARY KEY(ID, Restriction),
FOREIGN KEY(ID) REFERENCES Recipe(ID) ON UPDATE CASCADE ON DELETE CASCADE
);

CREATE TABLE MyRecipe(
UserID varchar(50) NOT NULL,
RecipeID INT,
Name varchar(255),
PrepTime INT,
Instructions varchar (1000),
MealType varchar(50),
PRIMARY KEY(UserID, RecipeID)

FOREIGN KEY (RecipeID) REFERENCES Recipe(ID), ON UPDATE CASCADE ON DELETE CASCADE,
FOREIGN KEY (UserID) REFERENCES Users(UserID), ON UPDATE CASCADE ON DELETE CASCADE
);

-- load excel data into Recipe, Ingredients, MealType, and DietaryRestrictions tables
