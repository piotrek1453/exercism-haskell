module SpaceAge (Planet(..), ageOn) where

data Planet = Mercury
            | Venus
            | Earth
            | Mars
            | Jupiter
            | Saturn
            | Uranus
            | Neptune
            deriving (Eq, Ord)

ageOn :: Planet -> Float -> Float
ageOn planet seconds
  | planet == Mercury = years 0.2408467
  | planet == Venus = years 0.61519726
  | planet == Earth = years 1
  | planet == Mars = years 1.8808158
  | planet == Jupiter = years 11.862615
  | planet == Saturn = years 29.447498
  | planet == Uranus = years 84.016846
  | planet == Neptune = years 164.79132
  where years divisor = (seconds/31557600)/divisor