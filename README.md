### Astronomy Calculator

A c++ program for stellar calculations that queries the HYG-Database, which can be found at https://github.com/astronexus/HYG-Database .

This program
  - Uses rapidjson to query a converted version of the database. https://github.com/miloyip/rapidjson
  - Outputs to the console:
    - Right Ascension
    - Declination
    - Distance in Parsecs
    - Distance in AU
    - Distance in Meters
    - Luminosity
    - Spectral type
  - Converts Distance in Parsec to AU
  - Converts Distnace in AU to meters
  - Calculates Apparent Brightness in Watts/(Meters<sup>2</sup>)

The queries run very fast! I have plans to add all additional columns of the database and produce more robust assertions and error handling.

Assistance with improvements: 

I'm all ears for information, critiques and pulls, especially with the following: 

  - Header parser, to modularize the initial JSON parse as an #include. 
  - Assertions and Error Handling