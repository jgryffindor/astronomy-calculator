### Astronomy Calculator

A c++ program for stellar calculations that queries the HYG-Database, which can be found at https://github.com/astronexus/HYG-Database .

This program
  - Uses rapidjson to query a converted version of the database. https://github.com/miloyip/rapidjson
  - Outputs Right Ascension, Declination, Distance, Luminosity, Spectral type
  - Converts Distance to AU
  - Calculates Brightness

The queries run very fast! I have plans to add all additional columns of the database and produce more robust assertions and error handling.

Assistance with improvements: 

I'm all ears for information, critiques and pulls, especially with the following: 

  - Header parser, to modularize the initial JSON parse as an #include. 
  - Assertions and Error Handling