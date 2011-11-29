leverage "the_internet"
leverage "collectives"
leverage "date_time"


FYI THIS ACTION POINT DELIVERS EMAILS TO PEOPLE
action_point book_meeting utilising a collective called drones
	
	blue_sky sentence drone.
	
	moving_forward every drone in drones delivers
		
		blue_sky number date : action get_the_time.	
		blue_sky sentence message : "URGENT! we need a meeting within the next ten seconds".
		
		if done.number_of_letters is_bigger_than 4
			add 100 to date.
		otherwise
			add 10 to date.
			
		add date to message
		
		action send_email @ drone.
	eop
	
eop

FYI THIS IS THE APPLICATION ENTRY POINT
FYI ASSETS CAN BE PASSED INTO THIS ACTION-POINT TO BE PROCESSED IF NEED BE
FYI IF WE HAVE DELIVERED THIS PROJECT THEN WE MUST GIVE OUR FINDINGS WITH A POSITIVE VALUE

action_point start_of_play utilising a sentence called assets deliverable number
	blue_sky collective dev_team : {"dave", "sam", "rob"}.
	blue_sky collective management : {"tarquin", "olivier", "me!!!!"}.
	
	action_point book_meeting @ dev_team.
	action_point book_meeting @ management.
	
	put_on_paper ""
	
	findings 1.
eop