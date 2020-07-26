<html>
<head>
    <link rel="stylesheet" type="text/css" href="navbar.css">
</head>
<body>
    <div class="topnav">
        <a class="home" href="/index.html">Home</a>
        <a href="/pantryUpdates.php"> Update Pantry</a>
        <a href="/searchRecipes.php">Search Recipes</a>
        <a href="/myRecipes.php">My Recipes</a>
   </div>
   <h1>
       Here you can add items to your pantry, delete items from pantry, or update already existing items.<br>
   </h1>
   <p> 
        To add an item, fill out all of the fileds below and click on the Add button.<br>
        To update an item, fill out your userID and the name of the item you want to update, then fill in the corresponding fields you are updating.<br>
        To delete an item, fill out your userID and name of the item you want to delete. <br>
   </p>
    <form action="" method="get">
      <label for="userID">userID:</label>
      <input type="text" id=\"userID\" name="userID"><br><br>
      <label for="item">Item Name:</label>
      <input type="text" id="item" name="item"><br><br>
      <label for="Quantity">Qty:</label>
      <input type="text" id="Quantity" name="Quantity"><br><br>
      <label for="Type">Type of Measurement:</label>
      <input type="text" id="Type" name="Type"><br><br>
      <label for="Expiration">Expiration Date (YYY-MM-DD):</label>
      <input type="text" id="Expiration" name="Expiration"><br><br>
      <input type="Submit" name="Add" value="Add Item"><br><br>
      <input type="Submit" name="Delete" value="Delete Item"><br><br>
      <input type="Submit" name="Update" value="Update Item"><br><br>
    </form>
</html>
</body>
<?php
    session_start();
   
    $id = $_GET["userID"];
    $item = $_GET["item"];
    $qty = $_GET["Quantity"];
    $type = $_GET["Type"];
    $date = $_GET["Expiration"];

    //connect to sql server
    $servername = "localhost";
    $username = "pantrycs411_user";
    $pass = "P@ntry!!";
    $dbname = "pantrycs411_ver1";
    $conn = mysqli_connect($servername, $username, $pass, $dbname);
    if (!$conn) {
        echo "<h1>we not connected</h1>";
    }
    
    if (isset($_GET['Add'])){
        $sql = "INSERT INTO `Pantry`(`UserID`, `Name`, `Quantity`, `Type`, `ExpirationDate`) VALUES (\"$id\",\"$item\",$qty,\"$type\",\"$date\")";
        $res = mysqli_query($conn, $sql);
    } else if (isset($_GET['Delete'])){
        $sql = "DELETE FROM Pantry WHERE UserID = '$id' AND Name = '$item'";
        $res = mysqli_query($conn, $sql);
    } else if (isset($_GET['Update'])){
        $sql = "UPDATE Pantry SET Quantity = '$qty', Type = '$type', ExpirationDate = '$date' WHERE UserID = '$id' AND Name = '$item'";
        $res = mysqli_query($conn, $sql);
    }

?>
