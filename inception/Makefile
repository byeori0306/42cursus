all:
	@mkdir -p /Users/dahee/Desktop/dahpark/data/mariadb
	@mkdir -p /Users/dahee/Desktop/dahpark/data/wordpress
	cd srcs && docker-compose up -d
down:
	cd srcs && docker-compose down
fclean:
	cd srcs && docker-compose down --rmi all -v
	docker image prune -a -f
	docker volume prune -f
	docker network prune -f
	@rm -rf /Users/dahee/Desktop/dahpark/data/mariadb
	@rm -rf /Users/dahee/Desktop/dahpark/data/wordpress
