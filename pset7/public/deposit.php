<?php
    // configuration
    require("../includes/config.php");
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("deposit.php");
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        cs50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST["amount"], $_SESSION["id"]);
        redirect("index.php");
    }
?>
