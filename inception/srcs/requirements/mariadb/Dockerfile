FROM debian:buster

RUN apt-get update && apt-get install -y mariadb-server vim

COPY tools/setup.sh .

RUN sed -i 's/127.0.0.1/0.0.0.0/g' /etc/mysql/mariadb.conf.d/50-server.cnf

COPY tools/setup.sh .
RUN chmod 755 setup.sh
ENTRYPOINT ["/setup.sh"]
CMD ["mysqld_safe"]
