<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["symbol"]);
        if (!$stock)
        {
            apologize("Could not find that stock symbol");
        }
        else
        {
            render("quote.php", ["symbol" => $stock["symbol"], "price" => $stock["price"], "name" => $stock["name"]]);
        }
    }
?>