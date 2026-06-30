module ReverseString (reverseString) where

reverseString :: String -> String
reverseString [] = []
reverseString string = last string:reverseString (init string)
