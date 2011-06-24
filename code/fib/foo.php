<?php
function fib($i) {
    if ($i < 2) 
        return $i;
    else 
        return fib($i - 1) + fib($i - 2);
}

echo fib(40);
echo "\n";
