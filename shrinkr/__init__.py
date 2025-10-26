from ._core import CompressorFactory, Compressor


def compress(files, ctype=None):
    if not files:
        raise ValueError("No files provided")

    if ctype is None:
        ctype = "rle"

    comp = CompressorFactory.create_by_name(ctype)
    comp.compress(files)


def decompress(files):
    if not files:
        raise ValueError("No files provided")

    with open(files[0], "rb") as f:
        first_byte = f.read(1)[0]

    comp = CompressorFactory.create_by_id(first_byte)
    comp.decompress(files)


def list_ctypes():
    return CompressorFactory.get_available_algorithms()


__all__ = ["compress", "decompress", "list_ctypes", "CompressorFactory", "Compressor"]
