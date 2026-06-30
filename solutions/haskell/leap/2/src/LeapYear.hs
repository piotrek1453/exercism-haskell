module LeapYear (isLeapYear) where

isLeapYear :: Integer -> Bool
isLeapYear year
  | modulo0 year 400= True
  | modulo0 year 4 && not (modulo0 year 100) = True
  | otherwise = False
  where modulo0 year divisor = year `mod` divisor == 0