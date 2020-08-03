<?php
    include_once("connector.php");
?>
<html>
<head>
</head>
<body style = "background-color: #F7F7F7">
    <h2> Please write the Recipe ID in the input box before selecting Make, Favorite, of Un-favorite</h2>
    <form action="" method="post">
        <label for="RecipeID">RecipeID:</label>
        <input type="text" id="RecipeID" name="RecipeID"><br><br>
        <input type="Submit" name = "Make" value="Make"><br><br>
        <input type="Submit" name = "Favorite" value="Favorite"><br><br>
        <input type="Submit" name = "Un-favorite" value="Un-favorite"><br><br>
    </form>
 </body>
 </html>
 <?php
    $recipeID = $_POST['Details'];
    $sql = "SELECT ID FROM currentUser";
    $res = mysqli_query($conn, $sql);
    while($row = mysqli_fetch_array($res)) $userID = $row['ID'];
 
 if (isset($_POST['Details']) || isset($_POST['Make']) || isset($_POST['Favorite']) || isset($_POST['Un-favorite'])){
        //recipe table
        if (isset($_POST['Make']) || isset($_POST['Favorite']) || isset($_POST['Un-favorite'])) $recipeID = $_POST['RecipeID'];
        $sql = "SELECT Recipe.*, GROUP_CONCAT(DISTINCT(MealType.Type) SEPARATOR \", \") AS Type, GROUP_CONCAT( DISTINCT(DietaryRestrictions.Restriction) SEPARATOR \", \") AS Diet FROM Recipe JOIN MealType ON Recipe.ID=MealType.ID JOIN DietaryRestrictions ON Recipe.ID=DietaryRestrictions.ID WHERE Recipe.ID = '$recipeID'";
        $rec_res = mysqli_query($conn, $sql);
        echo "<table border='1'>
        <tr style='background-color:#C2E0F9'>
        <th>ID</th> 
        <th>Name</th>
        <th>Instructions</th>
        <th>Prep Time</th>
        <th>Cook Time</th>
        <th>Servings</th>
        <th>Meal Types</th>
        <th>Dietary Restrictions</th>
        </tr>";
        while($row = mysqli_fetch_array($rec_res))
        {
            echo "<tr>";
            echo "<td>". $row['ID'] . "</td>";
            echo "<td>" . $row['Name'] . "</td>";
            echo "<td>" . $row['Instructions'] . "</td>";
            echo "<td>" . $row['PrepTime'] . "</td>";
            echo "<td>" . $row['CookTime'] . "</td>";
            echo "<td>" . $row['Servings'] . "</td>";
            echo "<td>" . $row['Type'] . "</td>";
            echo "<td>" . $row['Diet'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
        
        //ingredients table
        $iSQL = "SELECT Ingredients.Name as Ingredient, Ingredients.Quantity as Qty, Ingredients.Type as Type FROM `Ingredients` JOIN Recipe ON Ingredients.ID=Recipe.ID WHERE Recipe.ID = '$recipeID'";
        $ires = mysqli_query($conn, $iSQL);
        echo "<table border='1'>
        <tr>
        <th>Ingredient</th>
        <th>Qty</th>
        <th>Type</th>
        </tr>";
        while($row = mysqli_fetch_array($ires))
        {
            echo "<tr>";
            echo "<td>" . $row['Ingredient'] . "</td>";
            echo "<td>" . $row['Qty'] . "</td>";
            echo "<td>" . $row['Type'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
    }
    
    //favorite recipe to myRecipes
    if (isset($_POST['Favorite'])){
        $recipeID = $_POST['RecipeID'];
        $myRec = "SELECT * FROM Recipe WHERE ID='$recipeID'";
        $rec_res = mysqli_query($conn, $myRec);
        while ($row = mysqli_fetch_array($rec_res)){
            $name = $row['Name'];
            $prep = $row['PrepTime'];
            $cook = $row['CookTime'];
            $instructions = $row['Instructions'];
            $servings = $row['Servings'];
            $myRecipeSQL = "INSERT INTO `MyRecipe`(`UserID`, `RecipeID`, `Name`, `Instructions`, `PrepTime`, `CookTime`, `Servings`) VALUES (\"$userID\", \"$recipeID\", \"$name\", \"$instructions\",  \"$prep\",  \"$cook\",  \"$servings\" )";
            mysqli_query($conn, $myRecipeSQL);
            }
        //echo "<h1> You have favorited recipe ". $name . "; check your recipes tab to see your favorites. </h1>";
    }
    
    //remove recipe from favorites
    if (isset($_POST['Un-favorite'])){
        $recipeID = $_POST['RecipeID'];
        $myRecipeSQL = "DELETE FROM `MyRecipe` WHERE `UserID` = \"$userID\" AND `RecipeID` = \"$recipeID\"";
        mysqli_query($conn, $myRecipeSQL);
        //echo "<h1> You have un-favorited this recipe; check your recipes tab to see your favorites. </h1>";
    }
    
    //update pantry items
    if (isset($_POST['Make'])){
        $recipeID = $_POST['RecipeID'];
        $Isql = "SELECT Name, Quantity, Type FROM `Ingredients` WHERE ID = '$recipeID'";
        $ingredients = mysqli_query($conn, $Isql);
        $Psql = "SELECT Name, Quantity, Type FROM `Pantry` WHERE UserID = '$userID'";
        $pantry = mysqli_query($conn, $Psql);
        
            
        while($Prow = mysqli_fetch_array($pantry))
        {
            while ($Irow = mysqli_fetch_array($ingredients)){
                $name = $Irow['Name'];
                $qty = $Irow['Quantity'];
                $type = $Irow['Type'];
                if ($name == $Prow['Name'] && $type == $Prow['Type']){
                    $newQty = $Prow['Quantity'] - $qty;
                    if ($newQty <= 0){
                        $sql = "DELETE FROM Pantry WHERE UserID='$userID' AND Name = '$name'";
                        mysqli_query($conn, $sql);
                    }
                    $sql = "UPDATE Pantry SET Quantity = '$newQty' WHERE UserID='$userID' AND Name = '$name'";
                    mysqli_query($conn, $sql);
                }
            }
            mysqli_data_seek($ingredients, 0);
        }
        
        echo "<h1> You have made a recipe; check your pantry to see your updated inventory. </h1>";
    }
    
    
 
 
 ?>