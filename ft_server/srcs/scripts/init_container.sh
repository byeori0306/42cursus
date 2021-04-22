#!/bin/bash

service nginx start
service php7.3-fpm start
service php7.3-fpm status
service mysql restart
sleep infinity
