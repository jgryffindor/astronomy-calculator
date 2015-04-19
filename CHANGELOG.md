# CHANGELOG

	1.2.1
		^ CHANGELOG

	1.2.0
		^ main.cpp - removed comment
		^ hygdata_v3.json - formatted spacing

	1.1.1
		^ CHANGELOG
	1.1.0
		^ main.cpp
			+ Added function to convert distance in AU to distance in Meters
			^ Corrected brightness calculation to use distance in Meters
			+ Added console output for distance in Meters, as a function of distance in AU
			^ Corrected function declaration from HrId() to HygID()

	1.0.0 
		+ Added hygdata_v3.json by converting with Grunt
		+ Added rapidjson library 
		+ Integrated rapidjson parser to main.cpp
		+ Create basic menu structure
		+ Added functions to searchby ID, Hipparcos ID and Proper Name, with error handling
		+ Added functions to calculate luminosity and brightnesss

	0.2.0 - Added HYG stellar database .csv. 

	0.1.0 - Initial commit

	* -> Security Fix
	# -> Bug Fix
	$ -> Language fix or change
	+ -> Addition
	^ -> Change
	- -> Removed
	! -> Note