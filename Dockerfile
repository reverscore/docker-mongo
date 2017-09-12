FROM ubuntu:16.04
MAINTAINER Luis Elizondo, lelizondo@gmail.com

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update

################## BEGIN INSTALLATION ######################
# Install MongoDB Following the Instructions at MongoDB Docs
# Ref: http://docs.mongodb.org/manual/tutorial/install-mongodb-on-ubuntu/

# Add the package verification key
RUN apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv EA312927

# Add MongoDB to the repository sources list
RUN echo "deb http://repo.mongodb.org/apt/ubuntu xenial/mongodb-org/3.2 multiverse" | tee /etc/apt/sources.list.d/mongodb-org-3.2.list

# Update the repository sources list once more
RUN apt-get update

# Install MongoDB package (.deb)
RUN apt-get install -y mongodb-org

# Create the default data directory
RUN mkdir -p /data/db

COPY mongodb.conf /etc/mongodb.conf

##################### INSTALLATION END #####################

# Expose the default port
EXPOSE 27017
EXPOSE 28017

# Execute the command
CMD ["/usr/bin/mongod"]
