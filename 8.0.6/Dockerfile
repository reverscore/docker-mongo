FROM mongo:8.0.6-noble

ENV DEBIAN_FRONTEND=noninteractive
ENV GLIBC_TUNABLES=glibc.pthread.rseq=0

COPY mongodb.conf /etc/mongo/mongodb.conf

# Expose the default port
EXPOSE 27017
EXPOSE 28017

HEALTHCHECK --interval=30s --timeout=5s --start-period=30s --retries=3 \
  CMD mongosh --eval 'db.runCommand("ping").ok' --quiet || exit 1
