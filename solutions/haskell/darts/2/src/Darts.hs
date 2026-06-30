module Darts (score) where

score :: Float -> Float -> Int
score x y
  | rad <= 1 = 10
  | rad <= 5 = 5
  | rad <= 10 = 1
  | otherwise = 0
  where rad = radius [x, y]

radius :: [Float] -> Float
radius = sqrt . sum . map (^2)
