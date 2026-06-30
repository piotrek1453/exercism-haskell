module Pangram (isPangram) where

import Data.Char (toLower)

isPangram :: String -> Bool
isPangram [] = False
isPangram text = foldl (\acc c -> acc && (c `elem` map toLower text)) True ['a'..'z']