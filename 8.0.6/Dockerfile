FROM mongo:8.0.6-noble

ENV DEBIAN_FRONTEND=noninteractive
ENV GLIBC_TUNABLES=glibc.pthread.rseq=1

COPY mongodb.conf /etc/mongo/mongodb.conf

# Expose the default port
EXPOSE 27017
EXPOSE 28017
