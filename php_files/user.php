<?php
     include("connector.php");
     $userID = $_REQUEST['userID'];
     $login = $_REQUEST['login'];
     $signUp = $_REQUEST['signUp'];
     $password = $_REQUEST['password'];
    
    //insert user
    if(isset($_REQUEST['signUp'])){
        $sql = "INSERT INTO `Users` (`UserId`, `Password`) VALUES('$userID', '$password');";
        mysqli_query($conn, $sql);
        if (mysqli_error($conn)) echo("UserID is already taken");
        else {
            $sql0 = "DELETE FROM currentUser";
            mysqli_query($conn, $sql0);
            $sql = "INSERT INTO currentUser(ID, Password) VALUES('$userID','$password');";
            mysqli_query($conn, $sql);
            echo "<h1>Welcome to PantryTM! Use the navigation bar to naviagte to My Pantry and update your pantry items.</h1>";
        };
    } else if(isset($_REQUEST['login'])){
        $sql = "SELECT * FROM Users WHERE UserID = '$userID' AND Password = '$password'";
        $res = mysqli_query($conn, $sql);
        if (mysqli_num_rows($res)==0) echo("Incorrect username or password, please click on Home and try again");
        else {
            $sql0 = "DELETE FROM currentUser";
            mysqli_query($conn, $sql0);
            $sql = "INSERT INTO currentUser(ID, Password) VALUES('$userID','$password');";
            mysqli_query($conn, $sql);
            echo "<h1>Welcome to PantryTM! Use the navigation bar to naviagte to My Pantry and update your pantry items.</h1>";
        }
    } 
    
    
?>

