<?php
    include_once("connector.php");
?>
<html>
<body style = "background-color: #F7F7F7">
    <form action="" method="post">
        <label for="Search">Search Recipes:</label>
        <input type="text" id=\"Search\" name="Search"><br><br>
        <input type="Submit" value="Search"><br><br>
    </form>
 </body>
 </html>
<?php
    $name = $_POST["Search"];
    
    if (isset($_POST['Search'])){
        //call B+ Tree executable
        $command = escapeshellcmd('python bplus.py ' . $name);
        $output = shell_exec($command);
        $recipeArray = explode("*", $output);
        
        echo "<table border='1'>
        <tr>
        <th>ID</th>
        <th>Name</th>
        </tr>";
        echo "<form name=\"recipeDetails\" action=\"recipeDetails.php\" method=\"post\">";
        for($i=0; $i<count($recipeArray); $i++) {
            $recipe = $recipeArray[$i];
            parse_str($recipe, $recipeOut);
            $id = $recipeOut['id'];
            
            echo "<tr>";
            echo "<td><input type='Submit' name='Details' value='$id'></td>";
            echo "<td>" . $recipeOut['name'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
    } else{
        $sql = "SELECT ID, Name FROM Recipe WHERE Name LIKE \"%" . $name . "%\"";
        $res = mysqli_query($conn, $sql);
    
        echo "<table border='1'>
        <tr>
        <th>ID</th>
        <th>Name</th>
        </tr>";
        echo "<form name=\"recipeDetails\" action=\"recipeDetails.php\" method=\"post\">";
        while($row = mysqli_fetch_array($res))
        {
            $id = $row['ID'];
            echo "<tr>";
            echo "<td><input type='Submit' name='Details' value='$id'></td>";
            echo "<td>" . $row['Name'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
    }


?>
