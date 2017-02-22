#!/usr/bin/env php
<?php
    
    require(__DIR__ . "/../includes/config.php");
    
    // Check for two command line arguments
    if ($argc != 2)
    {
        exit("Usage: ./import file.txt \n");
    }
    
    
    // Check that file exists
    if (!file_exists($argv[1]))
    {
        exit("Cannot find specified file: " . $argv[1] . "\n");
    }
    
    // Make sure it is readable
    if (!is_readable($argv[1]))
    {
        exit("File " . $argv[1] . " is not readable \n");
    }
    
    // Open file
    $file = fopen($argv[1], "r");
    
    // Check for errors
    
    if ($file == FALSE)
    {
        exit("Issue opening file");
    }
    
    // Iterate over file
    while ($row = fgetcsv($file, 1000, "\t"))
    {
        CS50::query("INSERT INTO places 
        (country_code, postal_code, place_name, 
         admin_name1, admin_code1, admin_name2, 
         admin_code2, admin_name3, admin_code3, 
         latitude, longitude, accuracy) 
         VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)",
         $row[0], $row[1], $row[2], $row[3], $row[4],
         $row[5], $row[6], $row[7], $row[8], $row[9],
         $row[10], $row[11]);
    }
    
    // Close file
    fclose($file);
?>