all:
	cd srcs && docker-compose up -d
	docker exec -it mariadb sh -c "sh setup.sh"
down:
	cd srcs && docker-compose down
	docker image prune -a -f
