MongoDB on Docker, exposes two ports

Run with
	
	docker run -d -p 27017 -p 28017 luis/mongodb

Find out which ports docker created
	
	docker ps

Use mongo
	
	mongo --port someport