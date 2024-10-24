<?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $size = intval($_POST["size"]);
        echo "<table border='1'>";
        for ($x = 0; $x <= $size; $x++) {
			echo "<tr>";
			for ($y = 0; $y <= $size; $y++) {
				echo "<td>";
				if ($x == 0 && $y == 0) {
					// Top left corner, nothing
					echo "";
				} else if ($x == 0) {
					// Y values
					echo $y;
				} else if ($y == 0) {
					// X values
					echo $x;
				} else {
					// Product
					echo $x * $y;
				}
				echo "</td>";
			}
			echo "</tr>";
        }
        echo "</table>";
    }
?>