module ReverseString (reverseString) where

reverseString :: String -> String
reverseString = go []
  where
    go acc [] = acc
    go acc (x:xs) = go (x:acc) xs