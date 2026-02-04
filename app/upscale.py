import cv2
import matplotlib.pyplot as plt
import sys
import os
import time
import multiprocessing
import numpy as np


def get_output_path(input_path: str) -> str:
    folder_name = os.path.dirname(input_path)
    full_filename = os.path.basename(input_path)
    filename = full_filename.split('.')[0]
    return os.path.join(folder_name, f"{filename}_upscaled.jpg")


def is_image(input_path: str) -> bool:
    allowed_exts = ['jpg', 'jpeg', 'png']
    for ext in allowed_exts:
        if input_path.endswith(ext):
            return True
    return False


def denoise(image):
    return cv2.fastNlMeansDenoisingColored(image, None, 5, 5, 7, 10)


def brightness(image, value: int):
    return cv2.convertScaleAbs(image, alpha=1.0, beta=value)


def postprocess(image):
    sigma = 1.2  # Controls the amount of blurring in the mask
    amount = 1.2 # Controls the strength of the sharpening
    blurred = cv2.GaussianBlur(image, (0, 0), sigma)
    image = cv2.addWeighted(image, 1 + amount, blurred, -amount, 0)
    image = brightness(image, 2)
    image = denoise(image)
    return image


def upscale_image(input_path: str, model_path="ESPCN_x3.pb", model_name="espcn") -> None:
    img = cv2.imread(input_path)
    sr = cv2.dnn_superres.DnnSuperResImpl_create()
    sr.readModel(model_path)
    sr.setModel(model_name, 3)
    result = sr.upsample(img)
    result = postprocess(result)
    output_path = get_output_path(input_path)
    cv2.imwrite(output_path, result)


def check_and_upscale(input_path: str) -> None:
    if is_image(input_path):
        print("upscaling: " + input_path)
        upscale_image(input_path)


def main(args: list[str]) -> None:
    num_cpus = multiprocessing.cpu_count()
    num_threads = num_cpus // 2

    with multiprocessing.Pool(processes=num_threads) as pool:
        pool.map(check_and_upscale, args)
