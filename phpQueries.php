/*Name(String), quantity (int), type(string)

for loop to go through each enttry, insert into 1 by 1*/
/* No for loop in 
SQL */

/*structure of arrays
$currentUser = array(
    "userID" => "tester",
    "username" => "name"
)
$deleteUser = array(
    "userID" => "tester",
    "username" => "name"
)
//pantry for current user
$pantry = array(
    "item" => array(
        "name" => "ingredient"
        "quantity" => 3,
        "type" => "cup",
        "expiration" => '09/2020'
    )
);
//for an item user wants to delete/update
//variable shouldDeleteItem is checked when ANY item is going to be deleted (there should be logic that looks at the result of all the individual delete buttons)
$deleteItem = array(
    "name" = > "Ingredient",
    "userID" => "tester"
);
$updateItem = array(
    "name" = > "Ingredient",
    "userID" => "tester",
    "quantity" => 2
);
//search bar
$searchInput = "food name"
//filter 

*/

<?php
//connect to sql server

//inserting user
if (!$mysqli -> query("INSERT INTO Users(UserId, UserName) VALUES('$currentUser['userID']','$currentUser['username']')"))
    echo "UserID is taken, please pick another one";
//deleting user
$sql = "DELETE FROM Users WHERE UserID = '$deleteUser['userID']'";

//inserting into pantry
for ($x = 0; $x <=sizeof(pantry) ; $x++) {
        $sql = "INSERT INTO Pantry(UserID, Name, Quantity, Type, Expiration) VALUES ('$currentUser['userID']','$pantry[$x]['name']', '$pantry[$x]['quantity']', '$pantry[$x]['type']', '$pantry[$x]['expiration']')";
    }
}
//deleting from pantry
if (shouldDeleteItem) {
    $sql = "DELETE FROM Pantry WHERE UserID = '$deleteItem['userID']' AND Name = '$deleteItem['name']";
}
//updating from pantry 
if (shoudlUpdateItem){
    $sql = "UPDATE Pantry SET Quantity = '$updateItem['quantity']' WHERE UserID = '$updateItem['userID']' AND Name = '$updateItem['name']";
}

//recipe search bar
$sql = "SELECT Name, ID FROM Recipe WHERE Name LIKE "%'$searchInput'%"";
$sql = "SELECT Name, ID FROM myRecipe WHERE Name LIKE "%'$searchInput'%"";

//filtering results 

//close sql server
?>