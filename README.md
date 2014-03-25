MongoDB on Docker, exposes two ports

Run with
	
	docker run -itd -p 27017 --name mongodb luis/mongodb

Find out which ports docker created
	
	docker ps

Use mongo
	
	mongo --port someport
