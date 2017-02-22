<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // render page
        $position_symbols = cs50::query("SELECT symbol FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        render("sell.php", ["positions" => $position_symbols]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {

        // Get all rows with given symbol
        $position = cs50::query("SELECT symbol, shares FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"])[0];
        
        // Get total cash value for position
        $stock = lookup($position["symbol"]);
        $cash = $position["shares"] * $stock["price"];
        
        // Update cash in users table
        cs50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $cash, $_SESSION["id"]);
        cs50::query("DELETE FROM portfolios WHERE user_id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        
        
        // update history table
        CS50::query("INSERT IGNORE INTO history (user_id, shares, price, symbol, transaction) VALUES(?, ?, ?, ?, 'SELL')", $_SESSION["id"], $position["shares"], $stock["price"], $stock["symbol"]);
        
        redirect("index.php");
    }
?>