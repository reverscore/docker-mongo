MongoDB on Docker, exposes two ports

Based on the official mongodb image

The reason for this image is to modify the mongodb.conf and add the following:

```
setParameter=textSearchEnabled=true
```

THIS IMAGE IS EXCLUDED FROM snyk.com BECAUSE WE DON'T USE IT IN PRODUCTION. PLEASE DO NOT USE IT IN PRODUCTION

