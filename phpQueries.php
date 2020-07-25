/*Name(String), quantity (int), type(string)

for loop to go through each enttry, insert into 1 by 1*/
/* No for loop in 
SQL */

/*structure of array (every user has their own pantry array)
$users = array(
    "user" => array(
        "userID" => "tester",
        "username" => "name"
    ),
    "user 2" => array(
        "userID" => "tester2",
        "username" => "name2"
    )
);
$currentUser = array(
    "userID" => "tester",
    "username" => "name"
)
$pantry = array(
    "item" => array(
        "name" => "ingredient"
        "quantity" => 3,
        "type" => "cup"
    )
);
*/

<?php
//inserting into pantry
for ($x = 0; $x <=sizeof(pantry) ; $x++) {
        $sql = "INSERT INTO Pantry(UserID, Name, Quantity, Type) VALUES ('$currentUser['userID],'$pantry[x][name]', '$pantry[x][quantity]', '$pantry[x][type]')"
    }
}
//deleting from pantry
//updating from pantry 
?>