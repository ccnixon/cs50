<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render page
        render("buy.php");
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {

        // Check for negative integers or decimals
        if (!preg_match("/^\d+$/", $_POST["shares"]))
        {
            apologize("Please enter a non-negative integer");
        }
        
        // Get current price of purchase
        $stock = lookup($_POST["symbol"]);
        
        // Check to make sure stock is valid
        if(!$stock)
        {
            apologize("Could not find that stock");
        }
        
        $price = $stock["price"] * $_POST["shares"];
        
        // Get current cash position of user
        $cash = cs50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"])[0]["cash"];
        
        // Check to make sure user can afford purchase, else apologize
        if ($cash - $price < 0)
        {
            apologize("Not enough cash");
        }
        
        // Subtract cash from account
        cs50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $price, $_SESSION["id"]);
        
        // Update portfolios table
        cs50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"], $stock["symbol"], $_POST["shares"]);

        // Update history table
        CS50::query("INSERT IGNORE INTO history (user_id, shares, price, symbol, transaction) VALUES(?, ?, ?, ?, 'BUY')", $_SESSION["id"], $_POST["shares"], $stock["price"], $stock["symbol"]);
        
        redirect("index.php");
    }
?>