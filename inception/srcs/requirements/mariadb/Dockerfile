FROM debian:buster

RUN apt-get update && apt-get install -y mariadb-server vim

COPY tools/setup.sh .

CMD ["mysqld_safe"]
