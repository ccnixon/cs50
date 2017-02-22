<?php
    require("../includes/config.php");
    $rows = cs50::query("SELECT * from history WHERE user_id = ?", $_SESSION["id"]);
    render("history.php", ["transactions" => $rows]);
?>