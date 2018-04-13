<?php
   	include("connect.php");
   	
   	$link=Connection();

	$leftt=$_GET["le"];
	$rightt=$_GET["ri"];
	$strike=$_GET["st"];
	$ball=$_GET["ba"];
	$outt=$_GET["ou"];
	$roud=$_GET["r"];

	$query = "INSERT INTO `tempLog` (`leftt`, `rightt`, `strike`, `ball`, `outt`, `roud`) 
		VALUES ('".$leftt."','".$rightt."','".$strike."','".$ball."','".$outt."','".$roud."')"; 
   	
   	mysql_query($query,$link);
	mysql_close($link);

   	header("Location: index.php");
?>
