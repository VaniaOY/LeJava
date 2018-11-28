-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema gage
-- -----------------------------------------------------
drop database if exists gage;
-- -----------------------------------------------------
-- Schema gage
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `gage` DEFAULT CHARACTER SET utf8 ;
USE `gage` ;

-- -----------------------------------------------------
-- Table `gage`.`Producto`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `gage`.`Producto` (
  `idProductos` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Precio` DOUBLE UNSIGNED NOT NULL,
  `Nombre` VARCHAR(45) NOT NULL,
  `Foto` VARCHAR(45) NOT NULL,
  `Empresa` VARCHAR(45) NOT NULL,  
  `Descripcion` VARCHAR(250) CHARACTER SET 'latin1' COLLATE 'latin1_spanish_ci' NOT NULL,
  PRIMARY KEY (`idProductos`),
  UNIQUE INDEX `idProductos_UNIQUE` (`idProductos` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `gage`.`Usuario`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `gage`.`Usuario` (
  `idUsuario` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Nombre` VARCHAR(45) NULL,
  `Apellido` VARCHAR(45) NOT NULL,
  `Tipo` VARCHAR(1) NOT NULL,
  `correo` VARCHAR(45) NOT NULL,
  `contraseña` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idUsuario`),
  UNIQUE INDEX `idUsuario_UNIQUE` (`idUsuario` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `gage`.`Vendedor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `gage`.`Vendedor` (
  `idVendedor` INT UNSIGNED NOT NULL AUTO_INCREMENT,
  `Empresa` VARCHAR(100) NULL,
  `Direccion` VARCHAR(100) NOT NULL,
  `Telefono` VARCHAR(45) NOT NULL,
  `idAdmin` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`idVendedor`),
  UNIQUE INDEX `idVendedor_UNIQUE` (`idVendedor` ASC) VISIBLE
  INDEX `fk_Vendedor_Usuario_idx` (`idAdmin` ASC) VISIBLE,
  CONSTRAINT `fk_Vendedor_Usuario`
    FOREIGN KEY (`idAdmin`)
    REFERENCES `gage`.`Usuario` (`idUsuario`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `gage`.`PedidoU`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `gage`.`PedidoU` (
  `idPedidoU` INT NOT NULL AUTO_INCREMENT,
  `fechaCrea` DATETIME NOT NULL,
  `fechaEntrega` DATE NOT NULL,
  `cantidad` INT NOT NULL,
  `subtotal` DOUBLE NOT NULL,
  `Producto_idProductos` INT UNSIGNED NOT NULL,
  PRIMARY KEY (`idPedidoU`),
  UNIQUE INDEX `idPedidoU_UNIQUE` (`idPedidoU` ASC) VISIBLE,
  INDEX `fk_PedidoU_Producto_idx` (`Producto_idProductos` ASC) VISIBLE,
  CONSTRAINT `fk_PedidoU_Producto`
    FOREIGN KEY (`Producto_idProductos`)
    REFERENCES `gage`.`Producto` (`idProductos`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `gage`.`Producto_has_PedidoU`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `gage`.`Producto_has_PedidoU` (
  `Producto_idProductos` INT UNSIGNED NOT NULL,
  `PedidoU_idPedidoU` INT NOT NULL,
  PRIMARY KEY (`Producto_idProductos`, `PedidoU_idPedidoU`),
  INDEX `fk_Producto_has_PedidoU_PedidoU1_idx` (`PedidoU_idPedidoU` ASC) VISIBLE,
  INDEX `fk_Producto_has_PedidoU_Producto1_idx` (`Producto_idProductos` ASC) VISIBLE,
  CONSTRAINT `fk_Producto_has_PedidoU_Producto1`
    FOREIGN KEY (`Producto_idProductos`)
    REFERENCES `gage`.`Producto` (`idProductos`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Producto_has_PedidoU_PedidoU1`
    FOREIGN KEY (`PedidoU_idPedidoU`)
    REFERENCES `gage`.`PedidoU` (`idPedidoU`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `gage`.`Factura`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `gage`.`Factura` (
  `idFactura` INT UNSIGNED NOT NULL,
  `fechaEntrega` DATE NOT NULL,
  `Usuario_idUsuario` INT ZEROFILL UNSIGNED NOT NULL,
  `PedidoU_idPedidoU` INT NOT NULL,
  PRIMARY KEY (`idFactura`),
  UNIQUE INDEX `idFactura_UNIQUE` (`idFactura` ASC) VISIBLE,
  INDEX `fk_Factura_Usuario1_idx` (`Usuario_idUsuario` ASC) VISIBLE,
  INDEX `fk_Factura_PedidoU1_idx` (`PedidoU_idPedidoU` ASC) VISIBLE,
  CONSTRAINT `fk_Factura_Usuario1`
    FOREIGN KEY (`Usuario_idUsuario`)
    REFERENCES `gage`.`Usuario` (`idUsuario`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Factura_PedidoU1`
    FOREIGN KEY (`PedidoU_idPedidoU`)
    REFERENCES `gage`.`PedidoU` (`idPedidoU`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `gage`.`PedidoFav`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `gage`.`PedidoFav` (
  `idPedidoFav` INT NOT NULL AUTO_INCREMENT,
  `PedidoU_idPedidoU` INT NOT NULL,
  `cantidad` INT NOT NULL,
  `fecha` DATE NOT NULL,
  PRIMARY KEY (`idPedidoFav`),
  UNIQUE INDEX `idPedidoFav_UNIQUE` (`idPedidoFav` ASC) VISIBLE,
  INDEX `fk_PedidoFav_PedidoU1_idx` (`PedidoU_idPedidoU` ASC) VISIBLE,
  CONSTRAINT `fk_PedidoFav_PedidoU1`
    FOREIGN KEY (`PedidoU_idPedidoU`)
    REFERENCES `gage`.`PedidoU` (`idPedidoU`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;

drop table `gage`.`Stadistic`;
CREATE TABLE IF NOT EXISTS `gage`.`Stadistic` (
  `idStat` INT NOT NULL AUTO_INCREMENT,
  `fecha` date NOT NULL,
  `ganacia` DOUBLE NOT NULL,
  PRIMARY KEY (`idStat`))
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
