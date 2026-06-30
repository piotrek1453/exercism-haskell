module SpaceAge (Planet(..), ageOn) where

import qualified Data.Map as Map

data Planet = Mercury
            | Venus
            | Earth
            | Mars
            | Jupiter
            | Saturn
            | Uranus
            | Neptune
            deriving (Eq, Ord, Show, Enum, Bounded)

planets :: [Planet]
planets = [minBound .. maxBound]

divisors :: [Float]
divisors = [0.2408467, 0.61519726, 1, 1.8808158, 11.862615, 29.447498, 84.016846, 164.79132]

planetMap :: Map.Map Planet Float
planetMap = Map.fromList (zip planets divisors)

ageOn :: Planet -> Float -> Float
ageOn planet seconds = years planet
  where years planet = seconds/(31557600 * Map.findWithDefault 0 planet planetMap)