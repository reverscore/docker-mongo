MongoDB on Docker, exposes two ports

Based on the official mongodb image

The reason for this image is to modify the mongodb.conf and add the following:

```
setParameter=textSearchEnabled=true
```
